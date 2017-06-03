MARKDOWN  = $(shell ls *.md)
SCRIPTS   = includes
PDFLATEX  = xelatex
PANDOC    = pandoc

READER    = evince
#READER    = acroread

PDF       = $(MARKDOWN:.md=.pdf)
TEX       = $(MARKDOWN:.md=.tex)

TARGETS   = $(SCRIPTS) $(TEX) $(PDF)

all: $(TARGETS)

includes: includes.hs
	ghc --make includes.hs

# png-> eps
%.eps: %.png
	@convert $^ $@

# md -> tex
%.tex:   %.md
	@cat $< | ./includes | $(PANDOC) -s -o $@

# tex -> pdf
%.pdf:  %.tex
	$(PDFLATEX) $^
	$(PDFLATEX) $^

show: $(SCRIPTS) $(EPS) $(TEX) $(PDF)
	for pdf in $(PDF); do \
		$(READER) $$pdf; \
	done

clean:
	/bin/rm -rf $(TARGETS) _*.tex *.aux *.log *.out *.o *.hi *~
# END OF FILE

