/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bus.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:17:22 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/26 12:56:54 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdio.h>

int	bus_test(void)
{
#if defined(__GNUC__)
# if defined(__i386__)
    /* Enable Alignment Checking on x86 */
    __asm__("pushf\norl $0x40000,(%esp)\npopf");
# elif defined(__x86_64__) 
     /* Enable Alignment Checking on x86_64 */
    __asm__("pushf\norl $0x40000,(%rsp)\npopf");
# endif
#endif
    /* malloc() always provides aligned memory */
    char *cptr = malloc(sizeof(int) + 1);
    /* Increment the pointer by one, making it
       misaligned */
    int *iptr = (int *) ++cptr;
    /* Dereference it as an int pointer, causing
       an unaligned access */
    *iptr = 42;

    return 0;
}
