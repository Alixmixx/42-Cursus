/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:25 by amuller           #+#    #+#             */
/*   Updated: 2023/01/03 17:01:06 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>
# include <stddef.h>
# include <memory.h>
# include <signal.h>
# include <semaphore.h>
# include <limits.h>
# include <sys/wait.h>
# include <fcntl.h>

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

# define FORKS_SEM "/forks_sem"
# define PRINT_SEM "/print_sem"

# define FORK "has taken a fork"
# define IS_FULL "has ate enough"
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
	int				is_dead;
	pid_t			pid;
	size_t			last_meal;
	pthread_t		verif;
	struct s_info	*info;
}				t_philo;

typedef struct s_info
{
	int				nb_phil;
	int				dead;
	int				nb_time_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	sem_t			*print;
	sem_t			*forks;
	t_philo			philo;
}				t_info;

extern char	**environ;

//		GET_INFO
void	struct_init(t_info *info, int ac, char **av);

//		INIT
int		init_philo(t_info *info, pid_t *philos);

//		PHILO
void	philo_action(t_info *info, t_philo *philo);
void	philo_print(t_philo *philo, t_info *info, char *s);

// 		FORKS
int		philo_fork(t_info *info, pid_t *philos);

//		VERIF
void	*verif_action(void *data);

//		ERROR
void	exit_error(char *error, char *file, int ret);

//		TIME
size_t	get_time(void);

#endif
