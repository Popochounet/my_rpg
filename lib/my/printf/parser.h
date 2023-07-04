/*
** EPITECH PROJECT, 2022
** parser.h
** File description:
** protos for parser.c
*/

#pragma once

int wis_letter(wchar_t c);

int wis_nonzero_digit(wchar_t c);

int wis_digit(wchar_t c);

int wis_modifier(wchar_t c);

void free_flag(flag_t *flag);

void set_modifier(flag_struct_t *flag_struct, wchar_t c);

unsigned set_field_width(const wchar_t *format, flag_t *flag, va_list args);

unsigned set_precision(const wchar_t *format, flag_t *flag, va_list args);

unsigned set_length_modifier(const wchar_t *format, flag_t *flag);
