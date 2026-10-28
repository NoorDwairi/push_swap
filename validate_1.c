/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:22:25 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/28 10:22:27 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
long int limit;
long int num;

    num = 0;
    i = 0;
    limit = INT_MAX ;
if (arr[i] == '+' || arr[i] == '-')
    {
if(arr[i] == '-')
        limit = (long)INT_MAX + 1;
        i++;
    }
while(arr[i])
    {
if (num > (limit - (arr[i] - '0')) / 10)
return(0);
        num = num * 10 + (arr[i] - '0');
        i++;
    }
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