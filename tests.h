#ifndef TESTS_H
# define TESTS_H

# define RED "\033[1;31m"
# define YELLOW "\033[01;33m"
# define GREEN "\033[0;32m"
# define COLOR_END "\033[0m"

# define OK GREEN "[OK]" COLOR_END
# define WARN YELLOW "[WARN]" COLOR_END
# define ERROR RED "[ERROR]" COLOR_END
# define FAIL RED "[FAIL]" COLOR_END

int assert(int expr, const char *msg);
void test_gnl();
void test_ft_printf();
void test_ft_math();
void test_ht();
void val_vs_ref_benchmark();

#endif
