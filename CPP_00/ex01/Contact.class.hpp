/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:06:32 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/26 20:30:40 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class Contact
{
private:
        static std::string  Field_name[11];
        static std::string  Field_info[11];
        std::string         Field_value[11];
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

        void           set_information(std::string input, int fieldName);
        std::string    check_information(std::string input, int fieldName);
        std::string    check_birthdayDate(std::string input);
        std::string    check_firstName(std::string input);
        std::string    check_lastAndNickNameAndFavoriteMealAndUnderwearColor(std::string input);
        std::string    check_login(std::string input);
        std::string    check_postalAddress(std::string input);
        std::string    check_emailAddress(std::string input);
        std::string    check_phone(std::string input);
        std::string    check_darkSecret(std::string input);


public:
        Contact(void);
        ~Contact(void);

        bool    exists(void)const;
        int     add_contact(void);
        void    show_contact(void)const;
        void    show_contact_sumup(int)const;
};

#endif