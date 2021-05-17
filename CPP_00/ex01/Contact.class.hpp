/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:06:32 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/17 17:55:26 by nagresel         ###   ########.fr       */
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
        std::string         Field_value[11];
        std::string         firstName;
        enum Field {
        //        pkey,
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

        
        void    set_information(void);
        void    get_field(void);
        void    add_contact(void);
        void    show_contact(void)const;
//        void    display_Field(std::string field_value);
//        void    set_Field(int i,std::string value);
//        void    show_contact_list(void);
        void    show_contact_sumup(int)const;
        bool    exists(void)const;
        int     count_str(std::string str)const;
};

#endif