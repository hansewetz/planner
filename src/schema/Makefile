SQLFILES=$(wildcard *.sql)
ALLSQLFILES=$(patsubst %, $(ARTEFACTS)/schema/%, $(SQLFILES))

all: $(ALLSQLFILES)

$(ARTEFACTS)/schema/%.sql: %.sql
	cp $< $@

clean:
	rm -f $(ALLSQLFILES)

