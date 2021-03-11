Что исправить в sql, чтобы запрос начал работать

```
select count(a), sum(a) from (select NULL as a
union
select 2)
```
