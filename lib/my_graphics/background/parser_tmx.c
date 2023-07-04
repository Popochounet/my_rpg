/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that parse a tmx file into a sprite list
*/
#include "../include/background.h"
#include <stdlib.h>
#include <stdio.h>

static char * get_file(char const * path)
{
    struct stat data;
    memset(&data, 0, sizeof(struct stat));
    stat(path, &data);
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        write(2, "unable to open \"", 16);
        write(2, path, mystrlen(path));
        write(2, "\"\n", 2);
        return NULL;
    }
    char * buffer = malloc(data.st_size + 1);
    memset(buffer, 0, data.st_size + 1);
    ssize_t bytes_read = read(fd, buffer, data.st_size);
    close(fd);
    if (bytes_read != data.st_size) {
        write(2, "failed to read entire file\n", 26);
        free(buffer);
        return NULL;
    }
    return buffer;
}

static int my_add_number(int var, char c, char * buffer, int * i)
{
    if (buffer != NULL) {
        int len = 0;
        while (buffer[len + *i] != '\"') {
            len++;
        }
        return len;
    }
    int result = var;
    if ('0' <= c && c <= '9') {
        result *= 10;
        result += c - '0';
    }
    return result;
}

static tmx_t * get_tmx(char * buf, int * i, tmx_t * previous)
{
    tmx_t * tmx = create_tmx(previous); tmx_step_t step = NO_STEP; int j = 0;
    while (mystrncmp(buf + *i, "</tile>", 7) != 0) {
        if (mystrncmp(buf + *i, "<tile id=\"", 10) == 0) {
            step = ID; *i += 10;
        } if (mystrncmp(buf + *i, "width=\"", 7) == 0) {
            step = WIDTH; *i += 7;
        } if (mystrncmp(buf + *i, "height=\"", 8) == 0) {
            step = HEIGHT; *i += 8;
        } if (mystrncmp(buf + *i, "source=\"", 8) == 0) {
            step = PATH; *i += 8; int len = my_add_number(0, 0, buf, i);
            tmx->path = malloc(len + 1); tmx->path[len] = '\0';
        } if (buf[*i] == '\"' && step == PATH) { step = NO_STEP;
        } switch (step) {
        case ID: tmx->id = my_add_number(tmx->id, buf[*i], NULL, i); break;
        case WIDTH: tmx->width = my_add_number(tmx->width, buf[*i], NULL, i);
        break; case HEIGHT:
        tmx->height = my_add_number(tmx->height, buf[*i], NULL, i); break;
        case PATH: tmx->path[j] = buf[*i]; j++; break; default: break;
        } *i += 1;
    } return tmx;
}

static tmx_t * initializing_tmxs(char * buffer, int i, tmx_t * tmx)
{
    if (mystrncmp(buffer + i, "<tile id=\"", 10) == 0) {
        if (tmx == NULL) {
            tmx = get_tmx(buffer, &i, tmx);
        } else {
            tmx->next = get_tmx(buffer, &i, tmx);
            tmx = tmx->next;
        }
    }
    return tmx;
}

tmx_t * parser_tmx(char const * path)
{
    tmx_t * tmx = NULL;
    char * buffer = get_file(path);
    if (buffer == NULL) {
        write(2, "abort parsing\n", 14);
        return NULL;
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        tmx = initializing_tmxs(buffer, i, tmx);
    }
    free(buffer);
    for (int i = 0; tmx->previous != NULL; i++) {
        tmx = tmx->previous;
    }
    return tmx;
}
