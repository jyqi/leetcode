/*The Employee table holds all employees. Every employee has an Id, a salary, and there is also a column for the department Id.

+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
The Department table holds all departments of the company.

+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
Write a SQL query to find employees who have the highest salary in each of the departments. For the above tables, Max has the highest salary in the IT department and Henry has the highest salary in the Sales department.

+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+
*/

/*
An interesting SQL problem, It makes me to warm up the contents of SQL.
Need More to learn!
*/

Select Department.Name as Department, NEmployee.Name as Employee, NEmployee.Salary as Salary from Department, (select Name, Salary, DepartmentID from Employee, (Select max(Salary) AS mSalary, DepartmentID AS mDepartmentID from Employee group by DepartmentID) as mEmployee where Salary = mEmployee.mSalary and DepartmentID = mEmployee.mDepartmentID) as NEmployee where Department.Id = NEmployee.DepartmentID;