/*************************************************************************
*  File Name: autoptr.h
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Thu 31 Aug 2017 05:14:17 PM CST
*************************************************************************/

template <class X>
class auto_ptr {
	private:
		X* ptr;
		mutable bool owns;

	public:
		typedef X element_type;
		explicit auto_ptr(X* p = 0) : ptr(p),owns(p) {}
		auto_ptr(const auto_ptr& a) : ptr(a.ptr),owns(a.owns) {
			a.owns = 0;
		}
		template <class T> auto_ptr(const auto_ptr<T>& a)
			:ptr(a.ptr),owns(a.owns) {
				a.owns = 0;
			}
		auto_ptr& operator=(const auto_ptr& a) {
			if(&a != this) {
				if(owns)
					delete ptr;
				owns = a.owns;
				ptr = a.ptr;
				a.owns = 0;
			}
		}

		template <class T>auto_ptr& operator=(const auto_ptr<T>& a) {
			if(&a != this) {
				if(own)
					delete ptr;
				ptr = a.ptr;
				owns = a.owns;
				a.owns = 0;
			}
		}

		~auto_ptr() {
			if(owns)
				delete ptr;
		}

		X& operator*() const {return *ptr;}
		X* operator->() const{return ptr;}
		X* get() const {return ptr;}
		X* release const {owns = false; return ptr;}
};
