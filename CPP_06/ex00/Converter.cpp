/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:16:04 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/27 11:44:54 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"

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

void  Converter::setType(int type)
{
    _type = type;
}

void            Converter::findType()
{
    //nouvel algo
    std::stringstream    strStrm;
    int             len = _str.length();
    int             i = 0;

    if (len == 1 && _str[0] && !std::isdigit(_str[0]))
    {
        setType(TypeChar);
        _cValue = _str[0];
        return;
    }
    if (_str[0] == '+' || _str[0] == '-')
        strStrm << _str[i++];
    setType(TypeInt);
    
    while (i < len)
    {
        if (_str[i] == '.' && _type != TypeDouble)
        {
            setType(TypeDouble);
            strStrm << _str[i];
        }
        else if (_str[i] == 'e' && i < len - 1 &&
                    (_str[i + 1] == '-' || _str[i + 1] == '+' ||  std::isdigit(_str[i + 1])))
        {
            strStrm << _str[i] << _str[i + 1];
            i++;
            setType(TypeDouble);
        }
        else if (_str[i] == 'f' && i == len - 1 && _type == TypeDouble)
            setType(TypeFloat);
        else if (!std::isdigit(_str[i]))
        {
            setType(TypeInvalid);
            i = len;
        }
        else
            strStrm << _str[i];
        i++;
    }
    if  (_type == TypeFloat)
        strStrm >> _fValue;
    else if (_type == TypeDouble)
        strStrm >> _dValue;
    else if (_type == TypeInt)
    {
        long lValue;
        strStrm >> lValue;
        if (strStrm.fail() || lValue > std::numeric_limits<int>::max()
                    || lValue < std::numeric_limits<int>::min())
            setType(TypeInvalid);
    }
    else if (_type == TypeInvalid)
    {
        if (_str == "inff" || _str == "-inff" || _str == "+inff" || _str == "nanf")
        {
            _fValue = atof(_str.c_str()); //add '\0' at the end of _str
            setType(TypeFloat);
        }
        else if (_str == "inf" || _str == "-inf" || _str == "+inf" || _str == "nan")
        {
            _dValue = atof(_str.c_str()); //add '\0' at the end of _str
            setType(TypeDouble);
        }
    }
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