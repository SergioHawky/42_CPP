/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:54:16 by seilkiv           #+#    #+#             */
/*   Updated: 2026/10/15 12:16:05 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat1("John", 2);
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;

        Bureaucrat bureaucrat2("Jane", 130);
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;

        // Bureaucrat bureaucrat3("Alice", 1);
        // std::cout << bureaucrat3 << std::endl;
        // bureaucrat1.incrementGrade();
        // std::cout << bureaucrat3 << std::endl;

        Bureaucrat bureaucrat4("Bob", 0);
        std::cout << bureaucrat4 << std::endl;
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat4 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}