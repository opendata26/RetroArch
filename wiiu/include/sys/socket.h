#pragma once
#include <wiiu/types.h>
#include <stdint.h>
#include <sys/time.h>
#include <netinet/in.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SOL_SOCKET      -1

#define INADDR_ANY      0

#define AF_UNSPEC 0
#define AF_INET   2

#define SOCK_STREAM     1
#define SOCK_DGRAM      2

#define MSG_DONTWAIT    0x0020
/* #define MSG_DONTWAIT    0x0004 */

#define SO_DONTROUTE	5
#define SO_LINGER	13
#define SO_BROADCAST	6
#define SO_KEEPALIVE	9
#define SO_REUSEADDR    0x0004
#define SO_NBIO         0x1014


#define IP_MULTICAST_LOOP 		34
#define IP_ADD_MEMBERSHIP		35
#define IP_DROP_MEMBERSHIP		36

/* return codes */
#define SO_SUCCESS      0
#define SO_EWOULDBLOCK  6

struct ip_mreq  {
        struct in_addr imr_multiaddr;   /* IP multicast address of group */
        struct in_addr imr_interface;   /* local IP address of interface */
};

typedef uint32_t socklen_t;
typedef uint16_t sa_family_t;

struct sockaddr
{
   sa_family_t sa_family;
   char        sa_data[];
};

struct sockaddr_storage
{
   sa_family_t ss_family;
   char        __ss_padding[26];
};

struct linger
{
   int l_onoff;
   int l_linger;
};

struct hostent {
   char *h_name;       /* official name of host */
   char **h_aliases;   /* alias list */
   int h_addrtype;     /* host address type */
   int h_length;       /* length of address */
   char **h_addr_list; /* list of addresses */
};

#define h_addr h_addr_list[0] /* for backward compatibility */

void socket_lib_init();
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int socketclose(int sockfd);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
int listen(int sockfd, int backlog);
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
int shutdown(int sockfd, int how);
int socket(int domain, int type, int protocol);
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);

int socketlasterr(void);

#ifdef __cplusplus
}
#endif
