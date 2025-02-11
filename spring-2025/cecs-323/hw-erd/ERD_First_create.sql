-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2025-02-11 06:04:02.685

-- tables
-- Table: customers
CREATE TABLE customers (
    customer_id int  NOT NULL,
    first_name varchar(40)  NOT NULL,
    last_name varchar(40)  NOT NULL,
    phone varchar(20)  NOT NULL,
    street varchar(80)  NOT NULL,
    zip_code varchar(10)  NOT NULL,
    CONSTRAINT customers_pk PRIMARY KEY (customer_id)
);

-- Table: orders
CREATE TABLE orders (
    customer_id int  NOT NULL,
    order_date_time timestamp  NOT NULL,
    sold_by varchar(80)  NOT NULL,
    CONSTRAINT orders_pk PRIMARY KEY (customer_id,order_date_time)
);

-- foreign keys
-- Reference: orders_customers_fk_01 (table: orders)
ALTER TABLE orders ADD CONSTRAINT orders_customers_fk_01
    FOREIGN KEY (customer_id)
    REFERENCES customers (customer_id)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- End of file.

