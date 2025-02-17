/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:30:15 by atursun           #+#    #+#             */
/*   Updated: 2025/02/13 22:30:15 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

# define NUMBER_OF_PHILO 200

/* structlarda kullanmadığın değişkenleri kaldır*/

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

typedef struct s_inputs
{
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_to_eat;
}	t_inputs;

typedef struct s_philosopher
{
	int				id;
	int				eating;
	int				meals_eaten;
	int				start_time;
	int				last_time;
	int				*dead;
	t_inputs		inputs;
	t_thread		thread;
	t_mutex 		*write_lock;
	t_mutex 		*meal_lock;
	t_mutex			*right_fork;
	t_mutex			*left_fork;
}	t_philosopher;

typedef struct s_simulation
{
	t_mutex			meal_lock;			// Filozofların yemek yeme işlemleri sırasında senkronizasyon
	t_mutex			write_lock;			// Yazma işlemlerinin senkronize edilmesi
	t_mutex			*forks;
	t_philosopher	*philos;			// Filozofların tüm bilgilerini tutan dizi
}	t_simulation;

typedef enum e_error
{
	WRONG_ARGUMENT_COUNT,
	INVALID_PHILOS_NUMBER,
	ARGS_CANT_NEGATIVE_OR_ZERO,
}	t_error;


int	ft_atoi(const char *str);
int	throw_error_msg(t_error msg);
int inspect_args(int argc, char **argv);

void 	init_forks(t_mutex *forks, int num_of_philo);
void 	init_simulation(t_simulation *sim, t_philosopher *philos, t_mutex *forks);
void 	init_philos(t_simulation *sim, t_philosopher *philos, t_mutex *forks, char **argv);


#endif