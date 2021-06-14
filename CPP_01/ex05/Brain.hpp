/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:54:33 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/14 15:31:56 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <sstream>

class Brain
{
private:
    std::string     _address;
    int             _hemisphereLeft;
    int             _hemisphereRight;
    int             _corpusCallosum;

    int             getHemisphereLeft(void);
    int             getHemisphereRight(void);
    int             getCorpusCallosum(void);

public:
    Brain(void);
    ~Brain(void);
    std::string     identify() const;
};

#endif