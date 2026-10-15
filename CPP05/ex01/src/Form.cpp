/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:25:17 by seilkiv           #+#    #+#             */
/*   Updated: 2026/10/15 13:58:51 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form") , _isSigned(false) , _gradeSign(150) , _gradeExecute(150)
{
    std::cout << "Default Form constructor created" << std::endl;
}

Form::Form(const std::string &name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
        
    std::cout << "Form constructor created" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
    std::cout << "Form copy constructor created" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeSign() const
{
    return _gradeSign;
}

int Form::getGradeExecute() const
{
    return _gradeExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName() << ", Signed: " << form.getIsSigned() << ", Grade to Sign: " << form.getGradeSign() << ", Grade to Execute: " << form.getGradeExecute();
    return os;
}