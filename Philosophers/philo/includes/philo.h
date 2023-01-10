/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:25 by amuller           #+#    #+#             */
/*   Updated: 2022/12/23 15:32:32 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>

# define ERROR 1
# define SUCCESS 0
# define ERR_ARG "Invalid number of arguments"
# define ERR_AV "Argument not valid"
# define ERR_ENV "Environnement error"
# define ERR_MUT "Mutex error"
# define ERR_NO_PHI "Not enough philosophers"
# define ERR_DIE "Time to die is too low"
# define ERR_EAT "Time to eat is too low"
# define ERR_SLEEP "Time to sleep is too low"
# define ERR_TIME_EAT "There is no meal to eat"
# define ERR_MANY_PHI "Too many philosophers"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				nb_meal;
	size_t			last_meal;
	pthread_t		t_id;
	struct s_info	*info;
}				t_philo;

typedef struct s_info
{
	int				nb_phil;
	int				dead;
	int				full;
	int				nb_time_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_mutex_t	plate;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}				t_info;

extern char	**environ;

//		GET_INFO
void	struct_init(t_info *info, int ac, char **av);

//		INIT
int		init_philo(t_info *info);

//		PHILO
void	*philo_action(void *data);
void	philo_print(t_philo *philo, t_info *info, char *s);

// 		MUTEX
int		init_mutex(t_info *info);
int		destroy_mutex(t_info *info);

//		THREADS
int		thread_create_philo(t_info *info, t_philo *philo);
int		thread_destroy_philo(t_info *info);

//		ERROR
void	exit_error(char *error, char *file, int ret);

//		TIME
size_t	get_time(void);

//		CHECK
void	check_death(t_info *info, t_philo *philo);

#endif
