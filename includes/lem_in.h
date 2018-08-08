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
# include "../libft/includes/libft.h"

typedef struct s_edge	t_edge;
typedef struct s_vertex	t_vertex;

/*
** STRUCT FOR GRAPH EDGES
*/
struct					s_edge
{
	t_vertex			*vertex;
	t_edge				*next;
};

/*
** STRUCT FOR GRAPH NODE (VERTEX)
*/
struct					s_vertex
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
};

/*
** QUEUE
*/
typedef struct			s_queue
{
	struct s_qnode		*front;
	struct s_qnode		*rear;
}						t_queue;

typedef union			u_val
{
	t_vertex			*vertex;
	t_queue				*queue;
	char				*str;
}						t_val;

typedef struct			s_qnode
{
	t_val				val;
	struct s_qnode		*next;
}						t_qnode;

/*
** STRUCT FOR ANTS
*/
typedef struct			s_ant
{
	t_qnode				*room;
	int					ant;
	_Bool				finished;
	struct s_ant		*next;
}						t_ant;

/*
** STRUCT FOR DIFFERENT INFORMATION
*/
typedef struct			s_data
{
	t_ant				*all_ants;
	t_queue				graph;
	t_queue				paths;
	t_queue				file;
	char				**arr;
	char				*line;
	unsigned int		ants;
	_Bool				end;
	_Bool				start;
}						t_data;

/*
** MAIN FUNCTIONS
*/
t_queue					*ft_init_queue(void);
void					ft_enqueu(t_queue *queue, t_vertex *vertex,
						t_queue *qq, char *str);
void					ft_preenqueu(t_queue *queue,
									t_vertex *vertex, t_queue *qq);
int						ft_dequeu(t_queue *queue, int x);
void					ft_remove_queue(t_queue *queue, int x);
void					ft_remove_defined_queue(t_queue *queue, int x);
void					ft_print_queue(t_queue *queue);

/*
** ANT FUNTIONS
*/
int						ft_save_ants(t_data *app);
t_ant					*ft_init_ants_list(t_data *data);
void					ft_print_ants(t_ant *ants);
void					ft_remove_ant_list(t_data *data);
void					ft_error(void);

/*
**		READ INPUT
*/
void					ft_read_input(t_data *app);

/*
** VALIDATE INPUT
*/
int						ft_validate_comment(const char *str,
									short int *target, short int s);
int						ft_validate_room(const char *str);
int						ft_validate_tunel(const char *str);
void					ft_validate_vertexes(t_data *app);

/*
** SAVE VALUES
*/
void					ft_save_room(t_data *app, short int *target);
void					ft_save_tunel(t_data *app);

/*
** GRAPH
*/
t_vertex				*ft_init_vertex(short int *target, char *line);
void					ft_remove_graph(t_queue *graph);

/*
** UTILLITY
*/
int						ft_get_next_int(char **src);

/*
** ALGORITHM
*/
void					ft_bfs(t_vertex *start);
int						ft_restore_the_path(t_vertex *end, t_data *app);
void					ft_reset_graph(t_data *app);
int						ft_doubled_path(t_queue *paths);
void					ft_move_ants(t_data *data, t_queue *paths);
#endif
