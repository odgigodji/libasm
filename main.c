/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:33:05 by namerei           #+#    #+#             */
/*   Updated: 2021/05/06 17:33:08 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>
#include <errno.h>

size_t ft_strlen(char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strdup(const char *s);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

int get_next_line(char **line);

int main(int ac, char **av)
{
    if (av[1] && (!strcmp(av[1], "r") || !strcmp(av[1], "R") || !strcmp(av[1], "read"))) {
        printf("\x1B[35m""--------------ft_write test---------------""\x1B[0m\n");
        errno = 0;
        char *line = NULL;
        get_next_line(&line);
        printf("\x1B[34m""%s""\x1B[0m\n", line);
        printf("\x1B[33m""errno is [%d] %s\n", errno, strerror(errno));
    }
    else
    {
        int i = 0;
        printf("\x1B[35m""--------------ft_strlen test---------------\n""\x1B[0m");
        char *str[11] = {"", "a", "ab", "abc", "abcd", "teststringlengthis20" ,NULL};
        i = 0;
        while(str[i])
        {
            printf("\x1B[34m""str:%s\n""\x1B[0m", str[i]);
            printf("my:%zu\n", ft_strlen(str[i]));
            printf("or:%zu\n", strlen(str[i]));
            i +=1 ;
        }

        printf("\x1B[35m""--------------ft_strcpy test---------------\n""\x1B[0m");
        char s1[] = "000000000";
        char s2[] = "000000000";
        printf("\x1B[34m""s1:%s, s2:%s\n""\x1B[0m", s1, "hello");
        printf("my:|%s|\n", ft_strcpy(s1,"hello"));
        printf("or:|%s|\n", strcpy(s2, "hello"));


        printf("\x1B[35m""--------------ft_strcmp test---------------\n""\x1B[0m");
        const char *strings[11] = {"hello", "hello", "abc", "cba", "12345", "123", "123", "12345" , "", "2", NULL};
        i = 0;
        while(strings[i])
        {
            printf("\x1B[34m""s1:%s, s2:%s\n""\x1B[0m", strings[i], strings[i + 1]);
            printf("my:%d\n", ft_strcmp(strings[i], strings[i + 1]));
            printf("or:%d\n", strcmp(strings[i], strings[i + 1]));
            i +=2 ;
        }

        printf("\x1B[35m""--------------ft_strdup test---------------\n""\x1B[0m");
        char *dup = ft_strdup("hello");
        printf("my:%s\n", dup);
        free(dup);
        dup = ft_strdup("world");
        printf("my:%s\n", dup);

        printf("\x1B[35m""--------------ft_write test---------------""\x1B[0m\n");
        errno = 0;
        ft_write(1, "Hello world!\n", 13);
        printf("errno is [%d] %s\n", errno, strerror(errno));
        ft_write(-1, "sh", 2);
        printf("\x1B[33m""with negaive fd: errno is [%d] %s""\x1B[0m\n", errno, strerror(errno));
        errno = 0;
        ft_write(1, NULL, 2);
        printf("\x1B[33m""with NULL buffer: errno is [%d] %s""\x1B[0m\n", errno, strerror(errno));
    }
	return 0;
}

//nasm -f macho64 ft_strcmp.s && nasm -f macho64 ft_strcpy.s && nasm -f macho64 ft_strdup.s && nasm -f macho64 ft_strlen.s && nasm -f macho64  ft_write.s && nasm -f macho64 ft_read.s &&  gcc -c main.c && gcc *.o && rm *.o && ./a.out

int get_next_line(char **line)
{
    int ret = 1;
    int i = 0;
    char *str;
    char c;

    str = malloc(sizeof(char) * 10000);
    if (str == NULL)
        return (0);
    while (i < 10000)
        str[i++] = '\0';
    i = 0;
    while (ret > 0)
    {
        ret = (int)ft_read(0, &c, 1);
        if (ret > 0 && c != '\n')
            str[i++] = c;
        if (ret > 0 && c == '\n')
        {
            *line = str;
            return 1;
        }
    }
    *line = str;
    return 0;
}
