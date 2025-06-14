/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <lenygarcia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:03:36 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/06/14 13:16:26 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

static std::string	troncstr(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

Phonebook::Phonebook() 
{
	_index = 0;
}

Phonebook::~Phonebook() {}

void	Phonebook::displaycontacts() const
{
	if (!_index)
	{
		std::cout << "Please add a contact before trying to display the contacts." << std::endl;
		return ;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|    Index|First name| Last name| Nickname|" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (int i = 0; i < _index; i++)
	{
		std::cout << "|" << std::setw(10) << std::right << i + 1
				  << "|" << std::setw(10) << std::right << troncstr(_contacts[i].getfirstname())
				  << "|" << std::setw(10) << std::right << troncstr(_contacts[i].getlastname())
				  << "|" << std::setw(10) << std::right << troncstr(_contacts[i].getnickname()) << "|" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
}

void	Phonebook::addcontact()
{
	std::string	input;
	
	while (1)
	{
		std::cout << "Enter First name" << std::endl << ">";
		std::getline(std::cin, input);
		_contacts[_index].setfirstname(input);
		if (!input.empty() && input != "")
			break;
	}
	
	while (1)
	{
		std::cout << "Enter Last name" << std::endl << ">";
		std::getline(std::cin, input);
		_contacts[_index].setlastname(input);
		if (!input.empty() && input != "")
			break;
	}

	while (1)
	{
		std::cout << "Enter Nickname" << std::endl << ">";
		std::getline(std::cin, input);
		_contacts[_index].setnickname(input);
		if (!input.empty() && input != "")
			break;
	}

	while (1)
	{
		std::cout << "Enter Phone Number" << std::endl << ">";
		std::getline(std::cin, input);
		_contacts[_index].setphonenumber(input);
		if (!input.empty() && input != "")
			break;
	}

	while (1)
	{
		std::cout << "Enter Darkest secret" << std::endl << ">";
		std::getline(std::cin, input);
		_contacts[_index].setdarkestsecret(input);
		if (!input.empty() && input != "")
			break;
	}
	_index++;
}
