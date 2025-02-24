/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:04:04 by atursun           #+#    #+#             */
/*   Updated: 2025/02/24 13:18:52 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define RESET    "\033[0m"
# define RED      "\033[31m"
# define GREEN    "\033[32m"

# define NUMBER_OF_PHILO 200

typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;

typedef struct s_mutexes
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	t_mutex	*write_lock;
	t_mutex	*meal_lock;
}	t_mutexes;

typedef struct s_times
{
	int	die;
	int	eat;
	int	sleep;
	int	last_meal;
	int	born_time;
}	t_times;

typedef struct s_philo
{
	int			id;
	t_times		times;
	t_mutexes	mutexes;
	int			must_eat;
	t_thread		thread_id;
	int			meals_eaten;
	int			philo_count;
}	t_philo;

typedef struct s_simulation
{
	t_mutex	*forks;
	t_philo	*philos;
	t_mutex	meal_lock;
	t_mutex	write_lock;
}	t_simulation;

typedef enum e_error
{
	WRONG_ARGUMENT_COUNT,
	INVALID_PHILOS_NUMBER,
	ARGS_MUST_BE_DIGITS,
}	t_error;

int		ft_atoi(char *str);
void	ft_usleep(int mls);
int		get_current_time(void);
int		throw_error_msg(t_error msg);
void	*start_simulation(void *ptr);
void	*check_philo_eating_time(void *ptr);
void	finish_all(t_simulation *sim,  int count);
void	print_action(t_philo *philo, char *action);
void	create_threads(t_simulation *sim, t_philo *philo);

#endif
