SELECT name, bonus
FROM Employee NATURAL LEFT OUTER JOIN Bonus
WHERE bonus IS NULL OR bonus < 1000;