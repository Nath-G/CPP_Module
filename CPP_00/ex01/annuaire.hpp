/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annuaire.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:55:25 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/18 12:19:14 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANNUAIRE_HPP
# define ANNUAIRE_HPP

# include <iomanip>
# include <string>
# include <iostream>
# include "Contact.class.hpp"

void    show_startup(void);
void    show_contact_list(Contact contact[8]);
int     choose_contact(Contact contact[8]);

#endif