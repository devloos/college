-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2025-03-15 06:37:57.268

-- tables
-- Table: nurse_shifts
CREATE TABLE nurse_shifts (
    shift_date timestamp  NOT NULL,
    holiday_flag boolean  NOT NULL,
    employee_id int  NOT NULL,
    shift_name varchar(9)  NOT NULL,
    CONSTRAINT nurse_shifts_pk PRIMARY KEY (shift_date,employee_id,shift_name)
);

-- Table: nurses
CREATE TABLE nurses (
    employee_id int  NOT NULL,
    first_name varchar(80)  NOT NULL,
    last_name varchar(80)  NOT NULL,
    CONSTRAINT valid_name_constraint CHECK (first_name > 4 and last_name > 4) NOT DEFERRABLE INITIALLY IMMEDIATE,
    CONSTRAINT nurses_pk PRIMARY KEY (employee_id)
);

-- Table: shifts
CREATE TABLE shifts (
    shift_name varchar(9)  NOT NULL,
    shift_start_hour timestamp  NOT NULL,
    shift_end_hour timestamp  NOT NULL,
    CONSTRAINT valid_shift_hours CHECK (shift_start_hour > 0 and shift_end_hour < 23) NOT DEFERRABLE INITIALLY IMMEDIATE,
    CONSTRAINT valid_shift_name CHECK (shift_name > 5) NOT DEFERRABLE INITIALLY IMMEDIATE,
    CONSTRAINT shifts_pk PRIMARY KEY (shift_name)
);

-- foreign keys
-- Reference: nurse_shifts_fk (table: nurse_shifts)
ALTER TABLE nurse_shifts ADD CONSTRAINT nurse_shifts_fk
    FOREIGN KEY (employee_id)
    REFERENCES nurses (employee_id)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- Reference: shifts_fk (table: nurse_shifts)
ALTER TABLE nurse_shifts ADD CONSTRAINT shifts_fk
    FOREIGN KEY (shift_name)
    REFERENCES shifts (shift_name)  
    NOT DEFERRABLE 
    INITIALLY IMMEDIATE
;

-- End of file.

