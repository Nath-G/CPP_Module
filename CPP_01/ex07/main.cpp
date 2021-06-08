/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:51:36 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 19:57:03 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fstream>
# include <string>
# include <iostream>
# include <sstream>

int	err_manager(int ret, std::string errMsg)
{
	std::cout << "Error: " << errMsg << std::endl;
	return (ret);
}

int	args_checker(std::string &fileName, std::string &s1, std::string &s2, std::ifstream &fileStream)
{
	if (fileName.empty() || s1.empty() || s2.empty())
		return(err_manager(2, "empty string as argument is not supported."));
	if (!(fileStream.good()))
		return(err_manager(3, "problem from source file."));
	return (0);
}

int ft_replace(char **av)
{
    std::string			fileName(av[1]);
	std::string			oldStr(av[2]);
	std::string			newStr(av[3]);
	std::ifstream		sourceStream(fileName.c_str());
	std::ofstream		destStream;
	std::stringstream	tempStream;
	std::string			fileText;
	std::string			newFileName;
	size_t				pos = 0;
	size_t				oldLen = oldStr.length();
	size_t				newLen = newStr.length();
	int					ret;
    if ((ret = args_checker(fileName, oldStr, newStr, sourceStream)))
		return (ret);
    tempStream << sourceStream.rdbuf();
	fileText = tempStream.str();
    if (fileText.empty())
		return (err_manager(4, "source file is empty"));
	while ((pos = fileText.find(oldStr, pos)) != std::string::npos)
	{
		fileText.replace(pos, oldLen, newStr);
		pos += newLen;
	}
        newFileName = fileName + ".new";
	    destStream.open(newFileName.c_str());
        if (!(destStream.good()))
		    return(err_manager(4, "problem from destination file."));
	    destStream << fileText;
	return (ret);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (err_manager(1, "only 3 arguments are allowed."));
	return (ft_replace(av));
} 