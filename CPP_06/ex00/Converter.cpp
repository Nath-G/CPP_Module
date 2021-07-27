/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:16:04 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/27 09:27:31 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"
/*
Converter::Converter()
{

}*/

Converter::Converter(const std::string &value):_str(value), _type(TypeInvalid), _isValid(false)
{
    findType();
}

Converter::Converter(const Converter &src) : _str(src.getStr()), _type(src.getType())
{
    *this = src;
}

Converter::~Converter()
{

}

Converter &Converter::operator=(const Converter &rhs)
{
    if (this == &rhs)
        return (*this);
//    this->_str = rhs.getStr();
 //   this->_type = rhs.getType();
    return (*this);
}

std::string  Converter::getStr()const
{
    return(_str);
}

int  Converter::getType()const
{
    return(_type);
}

void            Converter::findType()
{

    if (_str == "-inf" || _str == "+inf" || _str == "nan")
        _type = TypeDouble;
    else if (_str == "-inff" || _str == "+inff" || _str == "nanf")
        _type = TypeFloat;
    else if (_str.length() > 3 && (_str.length() - 1) == 'f')
        _type = TypeFloat;
    else if (_str.length() > 2 && _str.find('.') != std::string::npos)
        _type = TypeDouble;
    else if (_str.length() == 1)
    {
        if (_str[0] >= '0' && _str[0] <= '9')
            _type = TypeInt;

        else if (_str[0] >= 32 && _str[0] <= 126)
            _type = TypeChar;
        else
            _type = TypeInvalid;
    }
    else
        _type = TypeInt;
}

void            Converter::IsFormatValid()
{
    int flag = -1;

   if (_type == TypeFloat)
        flag = isOnlyOneDot();
}

int    Converter::isOnlyOneDot()
{
//    size_t  i;
  //  int     dotNb;
    return 1;
}

std::ostream    &operator<<(std::ostream &os, const Converter &rhs)
{
    
    os << "ooo " << rhs.getStr() << " est du type " << rhs.getType() << std::endl;
    return (os);
}