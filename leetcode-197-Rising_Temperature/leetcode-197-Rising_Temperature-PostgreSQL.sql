SELECT w1.id
FROM Weather w1, Weather w2
WHERE DATE_PART('day', w1.recordDate::timestamp-w2.recordDate::timestamp) = 1 and w1.temperature > w2.temperature;