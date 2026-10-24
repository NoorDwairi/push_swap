/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 13:42:15 by dlababne          #+#    #+#             */
/*   Updated: 2026/10/24 13:42:17 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool     validate_sign(char *arr)
{
    int i;

    i = 0;
    if (arr[i] == '-' || arr[i] == '+')
    {
        if(!(arr[i + 1] >= '0' && arr[i + 1] <= '9'))
            return(0);
        else
            i++;
    }
    while(arr[i])
    {
        if (arr[i] == '-' || arr[i] == '+')
            return(0);
        i++;
    }
    return(1);
}

bool    validate_digits(char *arr)
{
    int i;
    
    i = 0;
    if(arr[i] == '-' || arr[i] == '+')
        i = 1;
    while(arr[i])
    {
        if(!(arr[i] >= '0' && arr[i] <= '9'))
            return(0);
        i++;
    }
    return(1);
}

bool    validate_overflow(char *arr)
{
    int i;

    i = 0;
    if(arr >= "2147483647" || arr <= "-2147483648")
        return(0);
    return(1);
}

int     validation(char **arr, int k)
{
    int i;
    int check;
    i = 0;
    while(i < k)
    {
        check = validate_sign(arr[i]);
        if (!check)
            return(ft_printf("ERROR\n"), 0);
        check = validate_digits(arr[i]);
        if (!check)
            return(ft_printf("ERROR\n"), 0);
        check = validate_overflow(arr[i]);
        if (!check)
            return(ft_printf("ERROR\n"), 0);
        i++;
    }
    return(1);
}