#include "get_next_line_bonus.h"

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (*(str + i) != '\0')
                i++;
        return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *news;
	size_t  i;

	i = 0;
	//printf(" strjoin entry, buf:%s ", s2);
	news = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (news == NULL)
		return (NULL);
	//printf("strjoin malloc\n");
	while (*s1 != '\0')
		news[i++] = *s1++;
	while (*s2 != '\0')
		news[i++] = *s2++;
	news[i] = '\0';
	return (news);
}

char    *ft_strjoin_n(char const *s1, char const *s2, size_t len)
{
	char    *news;
	size_t  i;
	size_t  j;

	j = 0;
	i = 0;
	//printf("strjoin entry, buf:%s|", s2);
	//printf("len:%lu\n|", len);
	news = (char *)malloc(ft_strlen(s1) + len + 2);
	if (news == NULL)
		return (NULL);
	//printf("strjoin malloc\n");
	while (*s1 != '\0')
		news[i++] = *s1++;
	while (s2[j] != '\0' && j <= len)
	{
		news[i++] = s2[j++];
		if (s2[j - 1] == '\n')
			break;
	}
	news[i] = '\0';
	return (news);
}
