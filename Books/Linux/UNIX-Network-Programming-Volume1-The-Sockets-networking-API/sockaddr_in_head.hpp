// file : sockaddr_in_head.hpp
// <netinet/in.h>

struct in_addr {
	in_addr_t s_addr; // 32-bit IPv4 address
					  // network byte ordered
};

struct sock_addr_in {
	uint8_t sin_len;	// length of struct (16)
	sa_family_t sin_family;	// AF_INET
	in_port_t	sin_port;	// 16-bit TCP or UDP port number

	struct in_addr sin_addr; // 32-bit IPv4 address
					  		 // network byte ordered

	char sin_zero[8];		// unused.
};


// <sys/socket.h>
// for casting, struct of sockaddr

struct sockaddr {
	uint8_t sa_len;
	sa_family_t sa_family; // address family: AF_xxx value
	char sa_data[14];	// protocol-specific address
};

int bind (int, struct sockaddr*, socklen_t);

struct sockaddr_in serv;

bind (sockfd, (struct sockaddr* ) &serv, sizeof (serv));


// IPv6 version

struct in6_addr {
	uint8_t s6_addr[16]; // 128-bit IPv6 address
						 // network byte ordered

};

#define SIN6_LEN		/* required for compile-time tests*/	
struct sockaddr_in6 {
	uint8_t sin6_len; 	//length of this struct (28)
	sa_family_t sin6_family; // AF_INET6
	in_port_t sin6_port; //transport layer port
	uint32_t sin6_flowinfo; //flowinfo undefined
	struct in6_addr sin6_addr; // IPv6 address
							   // network byte ordered
	uint32_t sin6_scope_id;  // set of interfaces of a scope
};

// <netinet/in.h>
// for casting, structure of sockaddr_storage

struct sockaddr_storage {
	uint8_t ss_len;	// length of this structure (implementation dependent)
	sa_family_t ss_family;  // address family : AF_xxx value;
	/* implementation dependent elements to provide:
	*  a) alignment sufficient to fulfill the alignment requirements of
	*	all socket address types that the system supports.
	*  b) enough storage to hold any type of socket address that the system supports. 
	*/
};


// little endian / big endian

#include <netinet/in.h>
uint16_t htons(uint16_t host-16-bit-value);
uint32_t htonl(uint32_t host-32-bit-value); // return network byte order

uint16_t ntohs(uint16_t net-16-bit-value);
uint32_t ntohl(uint32_t net-32-bit-value); // return host byte order

/*
名字以b(表示字节)开头的第一组函数 4.2 BSD 
名字以mem(表示内存)开头的第二组函数 ANSI C 
*/

#include <strings.h>

void bzero(void* dest, size_t nbytes);
void bcopy(const void* src, void* dest, size_t nbytes);
int bcmp(const void* ptr1, const void* ptr2, size_t nbytes); // return 0 if-eq, !0, otherwise.

/*
bzero 把目标字节串中指定数目的字节置为0， 用来初始化套结字地址结构
bcopy 将指定数目的字节从源字节串移动到目标字节串
bcmp 比较两个任意字节串，若相等返回值为0，否则返回值为非0
*/

//ANSI C 版本

#include <string.h>
void memset(void* dest, int c, size_t len);
void memcpy(void* dest, void * src, size_t nbytes);
int memcmp(const void* ptr1, const void* ptr2, size_t nbytes); // return 0 if-eq, !0, otherwise.

/*
memset 把目标字节串中指定数目的字节置为c.
记住memset最后两个参数的顺序方法是ANSI C的memXXX函数都需要一个长度参数，而且它总是最后一个参数。

memcpy 将指定数目的字节从源字节串移动到目标字节串, 当源字节串与目标字节串重叠时,bcopy能够正确处理，但memcpy的结果不可知，必须改用memmove函数。
记住memcpy两个参数的顺序的方法之一是C语言的赋值语句的顺序。
dest = src

memcmp 比较两个任意字节串，若相等返回值为0，否则返回值为非0
*/

/*
inet_aton/inet_addr/inet_ntoa 在点分十进制数串("192.168.10.5") 与它对应的32位的网络字节序二进制之间转换IPv4地址
inet_pton/inet_ntop对于IPv4和IPv6地址都适用
*/

#include <arpa/inet.h>

int inet_aton(const char* strptr, struct in_addr* addrptr ); // 字符串有效为1，否则为0
in_addr_t inet_addr(const char* strptr); //返回： 若字符串有效则为32位二进制网络字节序的IPv4地址，否则为INADDR_NONE
char* inet_ntoa(struct in_addr inaddr); //返回： 指向一个点分十进制数串的指针

/*
inet_aton将strptr指向的C字符串转换成一个32位网络字节序二进制值，并通过指针addrptr
来存储，若成功返回1，否则返回0
inet_aton有一个特征，如果addrptr指针为空，那么该函数仍然对输入的字符串执行有效性检查，但是不存储任何结果。

inet_addr进行相同的转换，返回值为32的网路字节序二进制值，该函数有一个问题，返回值INADDR_NONE(32位均为1）的值表示函数出错，255.255.255.255不能由该函数处理
推荐使用inet_aton代替

inet_ntoa函数将一个32位网络字节序IPv4地址转换成相应的点分十进制数串，由该函数的返回值指向的字符串驻留在静态内存中，意味着该函数是不可重入的。
*/


//inet_pton和inet_ntop 对于IPv4和IPv6 都适用。p和n分别代表presentation和numeric

#include <arpa/inet.h>

#define  INET_ADDRSTRLEN 16 // for IPv4 dotted-decimal
#define  INET6_ADDRSTRLEN 46  // for IPv6 hex string

int inet_pton(int family, const char* strptr, void* addrptr); //返回： 若成功，则为1， 若输入不是有效的表达格式，则为0， 若出错，则为-1
const char* inet_ntop(int family,const void* addrptr, char* strptr, size_t len); //返回： 若成功，则为则为指向结果的指针，若出错则为NULL

/*
这两个函数的family参数可以是AF_INET/AF_INET6. 如果以不被支持的地址族作为family参数，这两个函数就都返回一个错误，并将error置为EAF_NOSUPPORT.

inet_pton尝试转换由strptr指针所指的字符串，并通过addrptr指针存放结果。若成功则返回值为1，否则如果对所指定的family而言，输入的字符串不是有效的表达格式，那么
返回值为0

inet_ntop进行相反的转换，从数值格式(addrptr)转换到表达格式(strptr). len 参数是目标存储单元的大小，以免该函数溢出其调用者的缓冲区。
如果len太小，不足以容纳表达格式结果（包括结尾的空字符) 那么返回一个空指针，并置error为ENOSPC
inet_ntop函数的strptr参数不可以是一个空指针，调用者必须为目标存储单元分配内存，并指定其大小。调用成功时，这个指针就是该函数的返回值。
*/


// simplify IPv4 version for inet_pton
int inet_pton(int family, const char* strptr, void* addrptr)
{
	if(family == AF_INET)
	{
		struct in_addr in_val;

		if(inet_aton(strptr,&in_val)) 
		{
			memcpy(addrptr,&in_val,sizeof (struct in_addr));
			return 1;
		}
		return 0;
	}
	errno = EAFNOSUPPORT;
	return -1;
}

// simplify IPv4 version for inet_ntop
const char* inet_ntop(int family, const void* addrptr, char* strptr, size_t len)
{
	const u_char* p = (const u_char* ) addrptr;
	if(family == AF_INET)
	{
		char temp[INET_ADDRSTRLEN];

		snprintf(temp,sizeof(temp),"%d.%d.%d.%d",p[0],p[1],p[2],p[3]);

		if(strlen(temp) >= len)
		{
			errno = ENOSPC;
			return NULL;
		}
		strcpy(strptr,temp);
		return strptr;
	}
	errno = EAFNOSUPPORT;
	return NULL;
}


//inet_ntop的一个基本问题是：它要求调用者传递一个指向某个二进制地址的指针，二该地址通常包含在一个套结字地址结构中。
//所以，IPv4的使用方式为：

struct sockaddr_in addr;
inet_ntop(AF_INET,&addr.sin_addr,str,sizeof(str));

//IPv6的使用方式为：

struct sockaddr_in6 addr6;
inet_ntop(AF_INET6, &addr6.sin_addr, str, sizeof(str));

/*
我们自行定义了一个名为sock_ntop的函数

sockaddr指向一个长度为addrlen的套结字地址结构，本函数用它自己的静态缓冲区来来保存结果，而
指向该缓冲区的一个指针就是它的返回值。
对结果进行静态存储，导致该函数不可重入，且非线程安全。
*/

