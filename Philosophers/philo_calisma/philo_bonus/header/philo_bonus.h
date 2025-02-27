/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:43:48 by atursun           #+#    #+#             */
/*   Updated: 2025/02/27 19:43:48 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdbool.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
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
	t_mutex	*dead_lock;
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
	int			*dead;
	t_times		times;
	t_mutexes	mutexes;
	int			must_eat;
	t_thread	thread_id;
	int			meals_eaten;
	int			philo_count;
}	t_philo;

typedef struct s_simulation
{
	t_philo	*philos;
	int		dead_falg;
	t_mutex	dead_lock;
	t_mutex	meal_lock;
	t_mutex	write_lock;
}	t_simulation;


int		ft_atoi(char *str);
void	ft_usleep(int mls);
int		get_current_time(void);

int		inspect_args(int argc, char **argv);
void	print_action(t_philo *philo, char *action);

#endif