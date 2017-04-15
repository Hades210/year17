// file : exception_handlingSpec.cpp

class exception {
public:
	exception();
	exception(const exception& );
	exception& operator= (const exception&);

	virtual ~exception();
	virtual const char* what() const;
};

// The what() function can be used to obtain a string that is supposed to indicate something about the error that caused the exception.
// A programmer can define an exception by deriving from a standard-library exception like this:

struct My_error : runtime_error {
	My_error(int x) : runtime_error("My_error"), interesting_value(x) {}
	int interesting_value;
};


int main()
{
	try {
		// ...
	}
	catch(My_error& me) { // a My_error happened
		// we can use me.interesting_value and me.what()
	}
	catch(runtime_error& re) { // a runtime_error happened
		// we can use re.what()
	}
	catch(exception& e) { // some standard-library exception happened
		// we can use e.what()
	}
	catch(...) { // some unmentioned exception happened
		// we can do local cleanup
	}
}


// The make_exception_ptr() could be implemented as:

template <typename E>
exception_ptr make_exception_ptr(E e) noexcept;
try {
	throw e;
}
catch(...) {
	return current_exception();
}


// The intended use of nested_exception is as a base class for a class used by an exception handler to pass some information
// about the local context of an error together with a exception_ptr to the exception that 
// caused it to be called. For example:

struct My_error : runtime_error {
	My_error(const string&);
	// ...
};

void my_code()
{
	try {
		//
	}
	catch(...) {
		My_error err("something went wrong in my_code()");
		// ...
		throw_with_nested(err);
	}
}

// Now My_error information is passed along(rethrow) together with a nested_exception holding an excpetion_ptr to the exception caught.
// Futher up the call chain, we might want to look at the nested exception:

void user()
{
	try {
		my_code();
	}
	catch (My_error& err) {
		//  ... clean up My_error problems...
		try {
			rethrow_if_nested(err); // re-throw the nested exception, if any 
		}
		catch (Some_error& err2) {
			// ... clean up Some_error problems...
		}
	}
}
// This assumes that we know that some_error might be nested with My_error.
// An exception cannot propagate out of a noexcept function

// Assertions
// static_assert(e,s)		Evaluate e at compile time; give s as a compiler error message if !e
// assert(e)				If the macro DEBUG is not defined, evaluate e at run time and if !e, write a message to cerr and abort();
//							If DEBUG is defined, do nothing

template <typename T>
void draw_all(vector<T*>& v)
{
	static_assert(Is_base_of<Shape,T>(),"non-Shape type for draw_all()");

	for(auto p : v) {
		assert(p!=nullptr);
		//...
	}
}

// Asserts are(as they should be) used more frequently in production code than in small illustrative textbook examples.

// In <system_error>, the standard library provides a framework for reporting errors from the operating system and lower-level system components.

ostream& open_file(const string& path)
{
	auto dn = split_into_directory_and_name(path); 	// split into{path,name}

	error_code err {does_directory_exist(dn.first)}; // ask "the system" about the path

	if(err) { // err != 0 means error
		// ... see if anything can be done...
		if(cannot_handle_err)
			throw system_error(err);
	}

	//...
	return ofstream(path);
}

// In <system_error>, the standard library provides facilities for classifying error codes, for mapping system-specific error
// codes into more portable ones, and for mapping error codes into exceptions.

class error_code {
public:
	// representation: {value,category} of type {int, const error_category*}
};

ostream& open_file1(const string& path)
{
	auto dn = split_into_directory_and_name(path); // split into {path,name}

	if(error_code err {does_directory_exist(dn.first)}) { // ask "the system" about the path
		if(err == errc::permission_denied) {
			// ...
		}
		else if (error == errc::not_a_directory) {
			// ...
		}

		throw system_error(err); // can't do anything locally
	}

	return ofstream(path);
}

class error_category {
public:
	// ... interface to specific categories derived from error_category...
};



// code catching a system_error has its error_code available. For example:

try {
	// something
}
catch (system_error& err) {
	cout<<"caught system_error"<<err.what()<<"\n"; // error message

	auto ec err.code();
	cout<<"category: "<<ec.category().what()<<"\n";
	cout<<"value: "<<ec.value()<<"\n";
	cout<<"message: "<<ec.message()<<"\n";
}

