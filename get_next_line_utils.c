#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (*(str + i) != '\0')
                i++;
        return (i);
}

char    *ft_strjoin(char const *s1, char const *s2, size_t len)
{
	char    *news;
	size_t  i;
	size_t  j;

	j = 0;
	i = 0;
	//printf("strjoin after null\n");
	if (!s2[len])
		len = ft_strlen(s2);
	else
		len += 1;
	news = (char *)malloc(ft_strlen(s1) + len + 1);
	if (news == NULL)
		return (NULL);
	//printf("strjoin\n");
	while (*s1 != '\0')
		news[i++] = *s1++;
	while (s2[j] != '\0' && j <= len)
		news[i++] = s2[j++];
	news[i] = '\0';
	return (news);
}
