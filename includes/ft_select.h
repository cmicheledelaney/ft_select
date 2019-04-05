#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/includes/libft.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <time.h>
# include <curses.h>
# include <termcap.h>

// values of the different keys
# define ESC 0x1B
# define SPC 0x20
# define ENR 0xA
# define DEL 0x7E335B1B
# define BCKSP 0x7F
# define UP 0x415B1B
# define DOWN 0x425B1B
# define RIGHT 0x435B1B
# define LEFT 0x445B1B

# define CLEAR_SCREEN (tgetstr("cl", NULL))
# define SO (tgetstr("so", NULL))
# define SE (tgetstr("se", NULL))
# define CM (tgetstr("cm", NULL))
# define VE (tgetstr("ve", NULL))
# define VI (tgetstr("vi", NULL))
# define US (tgetstr("us", NULL))
# define TE (tgetstr("te", NULL))
# define TI (tgetstr("ti", NULL))
# define NORM (tgetstr("me", NULL))

typedef struct	s_files
{
	char		**files;
	int			nbr_files;
	int			*selected;
	int			index;
	bool		real;
}				t_files;

// term_config.c
void	set_term_configuration(void);
void	reset_term_configuration(void);

// signal_handling.c
void	signal_handler(void);
t_files	*update_files(t_files *updated_files);

// print_files.c
int		get_max_strlen(char **array, int start, int end);
int		get_nbr_cols(t_files *files);
void	print_filenames(t_files *files, int index, int nbr_cols);
void	set_window_size(void);

// print_selected_finish.c
void	print_selected(t_files *files);

// read_process_key.c
int		read_key(void);
void	process_key(int key, int *index, int nbr_cols, t_files *files);

// initialize.c
void	initialize_files(char **argv, int argc, t_files *files);
void	set_values(t_files *files);

#endif
