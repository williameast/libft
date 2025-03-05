#ifndef LIBFT_EXTRA_H
# define LIBFT_EXTRA_H

# include "libft.h"
# include <stddef.h>
# include <stdint.h>




size_t		count_words(char const *s, char c);
void		*safe_malloc(size_t bytes);
void		error_exit(char *msg);
#endif
