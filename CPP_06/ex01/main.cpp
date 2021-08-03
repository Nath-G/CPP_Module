/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:50:56 by nagresel          #+#    #+#             */
/*   Updated: 2021/08/03 18:31:51 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

uintptr_t serialize(Data* ptr)
{
    void *tmp = &ptr;
    uintptr_t *i = reinterpret_cast<uintptr_t*>(tmp);
    ptr->address = *i;
//    std::cout << "ptr =                         " << ptr << std::endl;
//    std::cout << "ptr->address decimal value:  " << ptr->address << std::endl;//ptr address decimal value
    return (*i);
}

Data* deserialize(uintptr_t raw)
{
//    std::cout << "raw : " << raw << std::endl;
    Data *dt = reinterpret_cast<Data *>(raw);
//    std::cout << "dt.address : " << dt->address << std::endl;// this is ptr address decimal value
//    std::cout << "dt : " << dt << std::endl; //this is raw value, then ptr address 

    return(dt);
}

int main()
{

    Data ptr;
    uintptr_t ptrAddress;
    std::cout << "ptr address =                 "<< &ptr << std::endl;
    ptrAddress = serialize(&ptr);
    Data *ptr2 = deserialize(ptrAddress);
    std::cout << "ptr2 adress:                  " << ptr2 << std::endl;
    std::cout << "ptr.address decimal value:   " << ptr.address << std::endl;
    std::cout << "ptr2->address decimal value: " << ptr2->address << std::endl;
}