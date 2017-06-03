SRCS      = $(shell find ../model/ -name \*.tmpl -printf '%f\n' )
model     = ../model
view      = ../view/Java/af

templates = $(foreach s,$(SRCS), $(addprefix $(view)/,$(s:.tmpl=.py)))
TARGETS   = $(templates)

all: $(TARGETS)

# tmpl -> py
$(view)/%.py:  $(model)/%.tmpl
	cheetah-compile --flat $^ --odir $(view)

view:
	python $(view)/view.py

clean:
	find $(view) -name "*.pyc" -delete
	find $(view) -name "*.py.bak" -delete
	rm $(templates)

# END OF FILE
