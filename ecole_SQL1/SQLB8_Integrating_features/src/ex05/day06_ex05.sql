COMMENT ON TABLE person_discounts IS 'Эта таблица содержит список персональных скидок (если они имеются) для каждого клиента из таблицы person в каждой из пиццерий из таблицы pizzeria';

COMMENT ON COLUMN person_discounts.id IS 'Это порядковый номер для скидки конкретного клиента в конкретной пиццерии';

COMMENT ON COLUMN person_discounts.person_id IS 'Это порядковый номер конкретного клиента из таблицы person';

COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Это порядковый номер конкретной пиццерии из таблицы pizzeria';

COMMENT ON COLUMN person_discounts.discount IS 'Это размер скидки';

