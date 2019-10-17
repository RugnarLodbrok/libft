#ifndef LIBFT_COMPAT
# define LIBFT_COMPAT
# ifdef _WIN32
# include <io.h>
# else
# include <unistd.h>
#endif

# ifndef ulong
typedef unsigned long ulong;
# endif

# ifndef ullong
typedef unsigned long long int ullong;
# endif

# ifndef uint
typedef unsigned int uint;
# endif

# ifndef ULLONG_MAX
# define ULLONG_MAX ULONG_LONG_MAX
# endif

# ifdef __APPLE__
#  define MACOS 1
# else
#  define MACOS 0
# endif

# ifndef LITTLE_ENDIAN
#  define LITTLE_ENDIAN 1234
#  define BIG_ENDIAN 4321
# endif

#endif
