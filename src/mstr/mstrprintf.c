#include "mstr.h"
#include <stdarg.h>

// static inline char	*choose_buffer(char *static_buf, char *fmt)
// {
// 	uint64_t	len;
//
// 	len = _strlen(fmt);
// 	len *= 2;
// 	if (BUFFER_SIZE >= len)
// 	{
// 		buflen = BUFFER_SIZE;
// 		return (static_buf);
// 	}
// 	buflen = len;
// 	return (mstralloc(len + 1));
// }
//
// char	*mstrcatvprintf(char *s, const char *fmt, va_list ap)
// {
// 	char		static_buf[BUFFER_SIZE];
// 	char		*buf;
// 	uint64_t	buflen;
// 	char		*s;
//
// 	buf = choose_buffer(static_buf, fmt, &buflen);
// 	/*
// 		*
// 		* Printf code here
// 		*
// 		*/
// 	s = mstrnew(buf);
// 	if (buf != static_buf)
// 		free(buf);
// 	return (s);
// }
//
// /* * * * * * * * * * * * * * * * * * * * * * * * *
//
//    - Concatenates a formated string to 's', can be used with an empty string to
//    simply create a new formated string
//
//    - The original pointer is assumed to be freed and can't be used
//
//  * * * * * * * * * * * * * * * * * * * * * * * * */
// char	*mstrcatprintf(char *s, const char *fmt, ...)
// {
// 	char	*t;
// 	va_list	ap;
//
// 	va_start(ap, fmt);
// 	t = mstrcatvprintf(s, fmt, ap);
// 	va_end(ap);
// 	return (t);
// }
