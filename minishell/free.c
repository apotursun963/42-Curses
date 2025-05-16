/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:58:25 by atursun           #+#    #+#             */
/*   Updated: 2025/04/02 14:58:25 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_token_list(t_list *token_lst)
{
	t_list	*tmp;
	t_token	*token;

	while (token_lst)
	{
		tmp = token_lst->next;
		token = (t_token *)token_lst->content;
		free(token->value);
		free(token);
		free(token_lst);
		token_lst = tmp;
	}
}

static void	free_inf(void *content)
{
	t_inf	*infile;

	infile = (t_inf *)content;
	if (infile)
	{
		free(infile->name);
		free(infile->eof);
		free((void *)infile);
	}
}

static void	free_outf(void *content)
{
	t_outf	*outfile;

	outfile = (t_outf *)content;
	if (outfile)
	{
		free(outfile->name);
		free((void *)outfile);
	}
}

static void	free_tree(void *root)
{
	t_node	*node;
	t_pipe	*pipe;
	t_exec	*exec;

	node = (t_node *)root;
	if (node->type == N_PIPE)
	{
		pipe = (t_pipe *)root;
		if (pipe->left)
			free_tree(pipe->left);
		if (pipe->right)
			free_tree(pipe->right);
		free(pipe);
	}
	else if (node->type == N_EXEC)
	{
		exec = (t_exec *)root;
		if (exec->argv)
			free(exec->argv);
		if (exec->infiles)
			ft_lstclear(&exec->infiles, free_inf);
		if (exec->outfiles)
			ft_lstclear(&exec->outfiles, free_outf);
		free(exec);
	}
}

void	free_shell(t_shell *shell)
{
	if (shell->token_lst)
		free_token_list(shell->token_lst);
	if (shell->env_arr)
		free_split(shell->env_arr);
	ft_lstclear(&shell->path, free);
	if (shell->input)
		free(shell->input);
	if (shell->trim_input)
		free(shell->trim_input);
	if (shell->cmd_path)
		free(shell->cmd_path);
	if (shell->root)
		free_tree(shell->root);
	init_shell(shell);
}
