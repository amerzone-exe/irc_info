/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerzone <amerzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:17:04 by amerzone          #+#    #+#             */
/*   Updated: 2026/04/08 13:39:17 by amerzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <map>

class Channel
{
	private:
		std::string							_name;
		std::vector<std::string>			_members;
		std::vector<std::string>			_operator;
		std::string							_topic;
		std::map<std::string, void (*)()>	_mode;
		unsigned int						_n_members;

		/*
		associer pour chaque mode une fonction qui modifie
		le channel.
		*/			
}