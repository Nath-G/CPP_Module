/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:16:04 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/27 20: 37:45 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"

std::string Converter::_stat[3] = {"valid","undisplayable", "impossible"};

Converter::Converter(const std::string &value):_str(value), _type(TypeInvalid)
{
    for (int i = 0; i < 4; i++)
        _status[i] = Valid;
    findType();
    convert();
    check_validity();
}

Converter::Converter(const Converter &src)
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

char             Converter::getCvalue()const
{
    return (this->_cValue);
}

void            Converter::setCvalue(char c)
{
    _cValue = c;
}

int             Converter::getIvalue()const
{
    return (this->_iValue);

}

void            Converter::setIvalue(int i)
{
    _iValue = i;
}


float             Converter::getFvalue()const
{
    return (this->_fValue);
}

void            Converter::setFvalue(float f)
{
    _fValue = f;
}

double             Converter::getDvalue()const
{
    return (this->_dValue);
}

void            Converter::setDvalue(double d)
{
    _dValue = d;
}

void            Converter::findType()
{
    std::stringstream    strStrm;
    int             len = _str.length();
    int             i = 0;

    if (len == 1 && _str[0] && !std::isdigit(_str[0]))
    {
        setType(TypeChar);
        setCvalue(_str[0]);
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
        setIvalue(lValue);//
        if (strStrm.fail() || lValue > INT_MAX
                    || lValue < INT_MIN)
            setType(TypeInvalid);
    }
    else if (_type == TypeInvalid)
    {
        if (_str == "inff" || _str == "-inff" || _str == "+inff" || _str == "nanf")
        {
            setFvalue(atof(_str.c_str())); //add '\0' at the end of _str
            setType(TypeFloat);
        }
        else if (_str == "inf" || _str == "-inf" || _str == "+inf" || _str == "nan")
        {
            setDvalue(static_cast<double>(atof(_str.c_str()))); //add '\0' at the end of _str
            setType(TypeDouble);
        }
    }
}

void        Converter::convert()
{
    if (_type == TypeChar)
        convert(_cValue);
    
    else if (_type == TypeInt)
        convert(_iValue);
    else if (_type == TypeFloat)
        convert(_fValue);
    else if (_type == TypeDouble)
        convert(_dValue);
}
   
void            Converter::convert(char c)
{
	this->_iValue = static_cast<int>(c);
    this->_fValue = static_cast<float>(c);
	this->_dValue = static_cast<double>(c);
}
void            Converter::convert(int i)
{
	this->_cValue = static_cast<char>(i);
    this->_fValue = static_cast<float>(i);
	this->_dValue = static_cast<double>(i);
}
void            Converter::convert(float f)
{
    this->_cValue = static_cast<char>(f);
    this->_iValue = static_cast<int>(f);
	this->_dValue = static_cast<double>(f);
}
void            Converter::convert(double d)
{
    this->_cValue = static_cast<char>(d);
    this->_iValue = static_cast<float>(d);
	this->_fValue = static_cast<double>(d);
}

void    Converter::check_validity()
{
    if ((getType() == TypeInt && _status[TypeInt] == Impossible) || getType() == TypeInvalid)
    {
        _status[TypeChar] = Impossible;
        _status[TypeFloat] = Impossible;
        _status[TypeDouble] = Impossible;
        _status[TypeInt] = Impossible;
    }
    else if (_iValue > 256 || _iValue < 0
            ||_fValue > 256 || _fValue < 0
            || _dValue > 256 || _dValue < 0)
        _status[TypeChar] = Impossible;
    else if ((getType() == TypeInt && !std::isprint(this->_cValue))
            || (TypeFloat && !std::isprint(this->_fValue))
            || (TypeDouble && !std::isprint(this->_dValue)))
		_status[TypeChar] = Undisplayable;
    if (!doubleIsValue() || !floatIsValue())
    {
        this->_status[TypeChar] = Impossible;
		this->_status[TypeInt] = Impossible;
    }
    if (getDvalue() != getFvalue() && floatIsValue())
        this->_status[TypeFloat] = Impossible;
}

bool Converter::floatIsValue(void) const
{
	return (!(std::isnan(this->_fValue) || std::isinf(this->_fValue)));
}

bool Converter::doubleIsValue(void) const
{
	return (!(std::isnan(this->_dValue) || std::isinf(this->_dValue)));
}


std::ostream    &operator<<(std::ostream &os, const Converter &rhs)
{
    os << "char: ";
    if (rhs._status[rhs.TypeChar] == rhs.Valid)
        os << "'"<< rhs.getCvalue() << "'" << std::endl;
    else
        os << rhs._stat[rhs._status[rhs.TypeChar]] << std::endl;
    os << "int: ";
    if (rhs._status[rhs.TypeInt] == rhs.Valid)
        os << rhs.getIvalue() << std::endl;
    else
        os << rhs._stat[rhs._status[rhs.TypeInt]] << std::endl;
    os << "float: ";
    if (rhs._status[rhs.TypeFloat] == rhs.Valid)
        os << std::fixed << std::setprecision(1) << rhs.getFvalue() << 'f' << std::endl;
    else
        os << rhs._stat[rhs._status[rhs.TypeFloat]] << std::endl;
    os << "double: ";
    if (rhs._status[rhs.TypeDouble] == rhs.Valid)
        os << std::fixed << std::setprecision(1) << rhs.getDvalue() << std::endl;
    else
        os  << rhs._stat[rhs._status[rhs.TypeDouble]] << std::endl;
    return (os);
}
