#include "get_next_line_bonus.h"
void    ft_bzero(void *buf, size_t count)
{
        unsigned char   *ptr;

        ptr = (unsigned char *)buf;
        while (count > 0)
        {
                *ptr = '\0';
                ptr++;
                count--;
        }
}

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (*(str + i) != '\0')
                i++;
        return (i);
}

void    *ft_calloc(size_t len, size_t size)
{
        void    *m;

        m = malloc(len * size);
        if (m == NULL)
                return (NULL);
        ft_bzero(m, len * size);
        return (m);
}

char *ft_realloc(char *str, size_t nsize)
{
        char *tmp;
        size_t i;

        i = 0;
        tmp = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
        if (!tmp)
                return (NULL);
        while (i < ft_strlen(str))
        {
                tmp[i] = str[i];
                i++;
        }
        tmp[i] = '\0';
        free(str);
        str = (char *)ft_calloc(nsize, sizeof(char));
        if (!str)
                return (NULL);
        i = 0;
        while (i < ft_strlen(tmp))
        {
                str[i] = tmp[i];
                i++;
        }
        free(tmp);
        return (str);
}
