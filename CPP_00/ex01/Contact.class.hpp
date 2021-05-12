/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:06:32 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/12 19:08:58 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class Contact
{
private:
        int                 index;
        static std::string  Field_name[11];
        std::string         firstName;
        enum Field {
                FirstName,
                LastName,
                NickName,
                Login,
                PostalAddress,
                EmailAddress,
                Phone,
                BirthdayDate,
                FavoriteMeal,
                UnderwearColor,
                DarkestSecret
        };
public:
        Contact(void);
        ~Contact(void);

        std::string         Field_value[11];
        void    set_information(void);
        void    get_Field(void);
        void    add_contact(void);
        void    display_contact(int);
        void    show_contact_list(void);
        void    show_contact(int);
        bool    exists(void);
};

#endif