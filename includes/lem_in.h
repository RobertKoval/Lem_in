/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:26:22 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 15:22:50 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
#include "../libft/includes/libft.h"

typedef struct s_edge	t_edge;
typedef struct s_vertex	t_vertex;
/*
** STRUCT FOR GRAPH NODE (VERTEX)
*/
typedef struct			s_vertex
{
	int					coor[2];
	char				*name;
	unsigned int		id;
	t_lluint			dist;
	short int			target;
	_Bool				visited;
	_Bool				locked;
	_Bool				ant;
	t_edge				*edges;
	t_vertex			*predecessor;
//	struct s_vertex		*next;
}						t_vertex;

/*
** STRUCT FOR GRAPH EDGES
*/
typedef struct			s_edge
{
	struct s_vertex		*vertex;
	struct s_edge		*next;
}						t_edge;

typedef struct			s_graph
{
	struct s_vertex		*vertex;
}						t_graph;

/*
** QUEUE
*/
typedef struct		s_queue
{
	struct s_qnode	*front;
	struct s_qnode	*rear;
}					t_queue;

typedef union		u_val
{
	t_vertex		*vertex;
	t_queue			*queue;
	char			*str;
}					t_val;

typedef struct		s_qnode
{
	t_val			val;
	struct s_qnode	*next;
}					t_qnode;

/*
** STRUCT FOR ANTS
*/
typedef struct		s_ant
{
	t_qnode			*room;
	int				ant;
	_Bool			finished;
	struct s_ant	*next;
}					t_ant;

/*
** STRUCT FOR DIFFERENT INFORMATION
*/
typedef struct		s_data
{
	t_ant			*all_ants;
	t_queue			graph;
	t_queue			paths;
	t_queue			file;
	char			**arr;
	char			*line;
	unsigned int	ants;
	_Bool			end;
	_Bool			start;
}					t_data;








/*
** MAIN FUNCTIONS
*/
//void				ft_parse_file(t_graph *graph, t_data *data);
//int					ft_find_paths(t_vertex *start, t_queue *path);
//void				ft_move_ants(t_data *data, t_queue *paths);
//int					ft_is_double_in(t_queue *paths);
//
///*
//** QUEUE FUNCTIONS
//*/
t_queue				*ft_init_queue(void);
void				ft_enqueu(t_queue *queue, t_vertex *vertex,
							t_queue *qq, char *str);
void				ft_preenqueu(t_queue *queue, t_vertex *vertex, t_queue *qq);
int					ft_dequeu(t_queue *queue, int x);
void				ft_remove_queue(t_queue *queue, int x);
void				ft_remove_defined_queue(t_queue *queue, int x);
void				ft_print_queue(t_queue *queue);
//
///*
//** ANT FUNTIONS
//*/
int					ft_save_ants(t_data *app);
t_ant				*ft_init_ants_list(t_data *data);
void				ft_print_ants(t_ant *ants);
void				ft_remove_ant_list(t_data *data);
//
///*
//** INPUT VALIDATION FUNCTION
//*/
//int					ft_is_comment(const char *str);
//int					ft_is_valid_room(const char *str);
//int					ft_is_edge_valid(t_data *data);
///*
//** ROOM MANAGMENT FUNCTION
//*/
//void				ft_save_room(t_graph *graph, t_data *data,
//						unsigned short int *target);
//
///*
//** DIFFERENT FUNCTIONS
//*/
void				ft_error(void);
//void				ft_remove_matrix(char **arr);
//t_uint				ft_get_id_by_name(t_graph *graph, char *name);
//t_vertex			*ft_get_start(t_graph *graph);
//long long int		ft_get_next_int(char **src);


/*
**		READ INPUT
*/
void ft_read_input(t_data *app);


//validate
int	ft_validate_comment(const char *str, short int *target, short int s);
int	ft_validate_room(const char *str);
int	ft_validate_tunel(const char *str);
void	ft_validate_vertexes(t_data *app);

//save values
void			ft_save_room(t_data *app, short int *target);
void	ft_save_tunel(t_data *app);


//graph func
t_vertex	*ft_init_vertex(short int *target, char *line);



//utill
int	ft_get_next_int(char **src);


//algo
void 	ft_bfs(t_vertex *start);
int 	ft_restore_the_path(t_vertex *end, t_data *app);
void	ft_reset_graph(t_data *app);
int 	ft_doubled_path(t_queue *paths);
void		ft_move_ants(t_data *data, t_queue *paths);
//debug
void print_graph(t_queue *graph);


//GRAPh
void	ft_remove_graph(t_queue *graph);

#endif
