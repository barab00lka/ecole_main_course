set enable_seqscan=off;
create index idx_person_name on person (upper(name));
explain analyze select p.name from person p join person_order po on p.id = po.person_id;
