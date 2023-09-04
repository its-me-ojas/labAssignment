class Employee:
    def __init__(self, emp_id, name, age, salary):
        self.emp_id = emp_id
        self.name = name
        self.age = age
        self.salary = salary

    def __str__(self):
        return f"{self.emp_id}\t{self.name}\t{self.age}\t{self.salary}"

def sort_employee_data(employee_data, key):
    if key == 1:
        return sorted(employee_data, key=lambda emp: emp.age)
    elif key == 2:
        return sorted(employee_data, key=lambda emp: emp.name)
    elif key == 3:
        return sorted(employee_data, key=lambda emp: emp.salary)
    else:
        print("Invalid sorting parameter")
        return employee_data

def main():
    employee_data = [
        Employee("161E90", "Raman", 41, 56000),
        Employee("161F91", "Himadri", 38, 67500),
        Employee("161F99", "Jaya", 51, 82100),
        Employee("171E20", "Tejas", 30, 55000),
        Employee("171G30", "Ajay", 45, 44000)
    ]

    print("Employee Table:")
    print("Employee ID Name Age Salary (PM)")
    for emp in employee_data:
        print(emp)

    while True:
        print("Name is Shubham Raj")
        print("Roll No - E22CSEU1680")
        print("\nSort Options:")
        print("1. Sort by Age")
        print("2. Sort by Name")
        print("3. Sort by Salary")
        print("4. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 4:
            break

        sorted_data = sort_employee_data(employee_data, choice)
        
        print("\nSorted Employee Table:")
        print("Employee ID\tName\tAge\tSalary (PM)")
        for emp in sorted_data:
            print(emp)

if __name__ == "__main__":
    main()
