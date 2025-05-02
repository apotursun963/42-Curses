/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asym_bin_tree.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:20:57 by atursun           #+#    #+#             */
/*   Updated: 2025/04/02 14:20:57 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*create_exec(t_list *token_lst)
{
	t_exec	*node;

	if (token_lst == NULL)
		return (NULL);
	node = (t_exec *)malloc(sizeof(t_exec));
	node->argv = get_argv(token_lst);
	node->infiles = NULL;
	node->outfiles = NULL;
	node->type.type = N_EXEC;
	get_infiles(token_lst, &node->infiles);
	get_outfiles(token_lst, &node->outfiles);
	return (node);
}

static void	*create_pipe(void *left, void *right)
{
	t_pipe	*node;

	node = (t_pipe *)malloc(sizeof(t_pipe));
	node->type.type = N_PIPE;
	node->left = left;
	node->right = right;
	return (node);
}

void	*tree(t_list *tokens)
{
	t_list	*node;
	t_list	*prev;
	t_token	*tok;
	void	*left;
	void	*right;

	prev = NULL;
	node = tokens;
	while (node)
	{
		tok = (t_token *)node->content;
		if (tok->type == PIPE)
		{
			if (prev)
				prev->next = NULL;
			left = tree(tokens);
			right = tree(node->next);
			if (prev)
				prev->next = node;
			return (create_pipe(left, right));
		}
		prev = node;
		node = node->next;
	}
	return (create_exec(tokens));
}
