/*
** sapin.c for LAFORET LALALALALA in /home/ovsepi_l/rendu/Piscine-C-sapin
** 
** Made by Ludovic Ovsepian
** Login   <ovsepi_l@epitech.net>
** 
** Started on  Sat Oct  5 07:40:18 2013 Ludovic Ovsepian
** Last update Mon Sep  1 23:25:34 2014 Ludovic Ovsepian
*/

#include <stdlib.h>

int	my_putchar(char a)
{
  write(1, &a, 1);
}

int	tronc(int n, int i)
{
  int	j;
  int	width;
  int	spaces;

  width = 2 * (n / 2) + 1;
  j = 0;
  spaces = ((4 * n) + (calc(n - 1)) - ((calc2(n - 1)) + n));
  while (i < n)
    {
      while (j < spaces - width / 2)
	{
	  my_putchar(' ');
	  j = j + 1;
	}
      j = 0;
      while (j < width)
	{
	  my_putchar('|');
	  j = j + 1;
	}
      j = 0;
      my_putchar('\n');
      i = i + 1;
    }
}

int	calc2(int n)
{
  int	compteur;
  int	alt;
  int	i;
  int	nb;
  
  i = 0;
  nb = 0;
  alt = - 1;
  compteur = 1;
  while (i < n)
    {
      nb = nb + compteur;
      i = i + 1;
      if (alt == 1)
	{
	  compteur = compteur + 1;
	}
      alt = - alt;
    }
    return (nb);
}

int	calc(int n)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (i <= n)
    {
      nb = nb + i;
      i = i + 1;
    }
  return (nb);
}

int	lines_star(int nb_lines, int *nb_star, int *spaces, int count_spaces)
{
  int	count_lines;
  int	count_star;

  count_lines = 0;
  count_star = 0;
  while (count_lines < nb_lines)
    {
      while (count_spaces < *spaces)
	{
	  my_putchar(' ');
	  count_spaces = count_spaces + 1;
	}
      count_spaces = 0;
      *spaces = *spaces - 1;
      while (count_star < *nb_star)
	{
	  my_putchar('*');
	  count_star = count_star + 1;
	}
      my_putchar('\n');
      *nb_star = *nb_star + 2;
      count_star = 0;
      count_lines = count_lines + 1;
    }
}

int	sapin(int taille)
{
  int	spaces;
  int	count_tri;
  int	nb_lines;
  int	nb_star;
  int	alt;
  int	inc_spaces;

  inc_spaces = 1;
  alt = 1;
  nb_star = 1;
  nb_lines = 4;
  spaces = ((4 * taille) + (calc(taille - 1)) - ((calc2(taille - 1)) + taille));
  count_tri = -1;
  while ((count_tri = count_tri + 1) < taille)
    {
      lines_star(nb_lines, &nb_star, &spaces, 0);
      nb_star = nb_star - (inc_spaces * 2) - 2;
      spaces = spaces + 1;
      spaces = spaces + inc_spaces;
      nb_lines = nb_lines + 1;
      if (alt == - 1)
	inc_spaces = inc_spaces + 1;
      alt = - alt;
    }
  tronc(taille, 0);
}

int	main(int ac, char **av)
{
  sapin(atoi(av[1]));
}
