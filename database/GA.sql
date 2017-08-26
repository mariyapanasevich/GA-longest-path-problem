--Create tables--
CREATE TABLE public."Algorithm"
(
  "ID_algorithm" integer NOT NULL,
  "Name" character(100),
  CONSTRAINT "ID" PRIMARY KEY ("ID_algorithm")
);

CREATE TABLE public."GA"
(
  "ID_task" integer,
  "Vertex" integer,
  "Edge" integer,
  "Time" real,
  "SizeNewPopulation" integer,
  "Path" character(255),
  "LengthPath" integer,
  "numberExperement" integer NOT NULL DEFAULT nextval('"GA_numberExperement_seq"'::regclass),
  CONSTRAINT "numberExperement" PRIMARY KEY ("numberExperement"),
  CONSTRAINT ga_fkey_id_task FOREIGN KEY ("ID_task")
      REFERENCES public."Task" ("ID_task") MATCH SIMPLE
      ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE public."Task"
(
  "Name" character(100),
  "ID_task" integer NOT NULL DEFAULT nextval('"Task_ID_task_seq"'::regclass),
  CONSTRAINT "Task_pkey" PRIMARY KEY ("ID_task")
);

CREATE TABLE public.gabetweenvertex
(
-- Унаследована from table "GA":  "ID_task" integer,
-- Унаследована from table "GA":  "Vertex" integer,
-- Унаследована from table "GA":  "Edge" integer,
-- Унаследована from table "GA":  "Time" real,
-- Унаследована from table "GA":  "SizeNewPopulation" integer,
-- Унаследована from table "GA":  "Path" character(255),
-- Унаследована from table "GA":  "LengthPath" integer,
-- Унаследована from table "GA":  "numberExperement" integer NOT NULL DEFAULT nextval('"GA_numberExperement_seq"'::regclass),
  firstvertex integer,
  secondvertex integer,
  numstep integer,
  CONSTRAINT "numExpwithstepBetweenVertex" PRIMARY KEY ("numberExperement")
);

CREATE TABLE public.gainallgraph
(
-- Унаследована from table "GA":  "ID_task" integer,
-- Унаследована from table "GA":  "Vertex" integer,
-- Унаследована from table "GA":  "Edge" integer,
-- Унаследована from table "GA":  "Time" real,
-- Унаследована from table "GA":  "SizeNewPopulation" integer,
-- Унаследована from table "GA":  "Path" character(255),
-- Унаследована from table "GA":  "LengthPath" integer,
-- Унаследована from table "GA":  "numberExperement" integer NOT NULL DEFAULT nextval('"GA_numberExperement_seq"'::regclass),
  id_algorithm integer,
  persent real,
  CONSTRAINT "numExp" PRIMARY KEY ("numberExperement"),
  CONSTRAINT ga_between_vertex_fkey_id_task FOREIGN KEY ("ID_task")
      REFERENCES public."Task" ("ID_task") MATCH SIMPLE
      ON UPDATE CASCADE ON DELETE CASCADE,
  CONSTRAINT ga_in_all_fkey_id_algorithm FOREIGN KEY (id_algorithm)
      REFERENCES public."Algorithm" ("ID_algorithm") MATCH SIMPLE
      ON UPDATE CASCADE ON DELETE CASCADE,
  CONSTRAINT ga_in_all_fkey_id_task FOREIGN KEY ("ID_task")
      REFERENCES public."Task" ("ID_task") MATCH SIMPLE
      ON UPDATE CASCADE ON DELETE CASCADE
)
INHERITS (public."GA");

CREATE TABLE public.gainallgraphwithstep
(
-- Унаследована from table gainallgraph:  "ID_task" integer,
-- Унаследована from table gainallgraph:  "Vertex" integer,
-- Унаследована from table gainallgraph:  "Edge" integer,
-- Унаследована from table gainallgraph:  "Time" real,
-- Унаследована from table gainallgraph:  "SizeNewPopulation" integer,
-- Унаследована from table gainallgraph:  "Path" character(255),
-- Унаследована from table gainallgraph:  "LengthPath" integer,
-- Унаследована from table gainallgraph:  "numberExperement" integer NOT NULL DEFAULT nextval('"GA_numberExperement_seq"'::regclass),
-- Унаследована from table gainallgraph:  id_algorithm integer,
-- Унаследована from table gainallgraph:  persent real,
  numstep integer,
  CONSTRAINT "numExpwithstep" PRIMARY KEY ("numberExperement"),
  CONSTRAINT ga_in_all_step_fkey_id_algorithm FOREIGN KEY (id_algorithm)
      REFERENCES public."Algorithm" ("ID_algorithm") MATCH SIMPLE
      ON UPDATE CASCADE ON DELETE CASCADE,
  CONSTRAINT ga_in_all_step_fkey_id_task FOREIGN KEY ("ID_task")
      REFERENCES public."Task" ("ID_task") MATCH SIMPLE
      ON UPDATE CASCADE ON DELETE CASCADE
)
INHERITS (public.gainallgraph);

CREATE TABLE public.gabetweenvertex
(
-- Унаследована from table "GA":  "ID_task" integer,
-- Унаследована from table "GA":  "Vertex" integer,
-- Унаследована from table "GA":  "Edge" integer,
-- Унаследована from table "GA":  "Time" real,
-- Унаследована from table "GA":  "SizeNewPopulation" integer,
-- Унаследована from table "GA":  "Path" character(255),
-- Унаследована from table "GA":  "LengthPath" integer,
-- Унаследована from table "GA":  "numberExperement" integer NOT NULL DEFAULT nextval('"GA_numberExperement_seq"'::regclass),
  firstvertex integer,
  secondvertex integer,
  numstep integer,
  CONSTRAINT "numExpwithstepBetweenVertex" PRIMARY KEY ("numberExperement")
)
INHERITS (public."GA");

--insert data in tables --
INSERT INTO public."Algorithm" ("ID_algorithm","Name") VALUES
    (1,'Genetic Algorithm using non - intersecting paths'),
    (2,'Genetic Algorithm using intersecting paths'),
    (3,'Genetic Algorithm using a mutation mechanism'),
    (4,'Genetic Algorithm using non - intersecting paths and intersecting paths');

INSERT INTO public."Task" ("ID_task","Name") VALUES
    (1,'Genetic Algorithm in all graph'),
    (2,'Genetic Algorithm between two vertex');
