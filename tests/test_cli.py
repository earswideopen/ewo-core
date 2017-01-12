#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
test_cli
----------------------------------

Tests for `cli` module.
"""

from click.testing import CliRunner

from ewo import cli


def test_cli_help():
    runner = CliRunner()
    help_result = runner.invoke(cli.main, ['--help'])
    assert help_result.exit_code == 0
    #  assert 'Usage: ewo [OPTIONS]' in help_result.output


def test_cli_sample_rate():
    runner = CliRunner()
    smp_result = runner.invoke(cli.main, ['--sample-rate'], '44100')
    assert smp_result.exit_code == 2


def test_cli_width():
    runner = CliRunner()
    width_result = runner.invoke(cli.main, ['--width'], '2')
    assert width_result.exit_code == 2


def test_cli_channel_number():
    runner = CliRunner()
    channel_result = runner.invoke(cli.main, ['--channel-number'], '2')
    assert channel_result.exit_code == 2


#  import pytest
#
#  from contextlib import contextmanager
#  from click.testing import CliRunner
#
#  from ewo import ewo
#  from ewo import cli
#
#
#  @pytest.fixture
#  def response():
#      """Sample pytest fixture.
#      See more at: http://doc.pytest.org/en/latest/fixture.html
#      """
#      # import requests
#      # return
#      requests.get('https://github.com/audreyr/cookiecutter-pypackage')
#
#
#  def test_content(response):
#      """Sample pytest test function with the pytest fixture as an argument.
#      """
#      # from bs4 import BeautifulSoup
#      # assert 'GitHub' in BeautifulSoup(response.content).title.string
#
#
#  #  def test_command_line_interface():
#  #      runner = CliRunner()
#  #      result = runner.invoke(cli.main)
#  #      assert result.exit_code == 0
#  #      assert 'ewo.cli.main' in result.output
#  #      help_result = runner.invoke(cli.main, ['--version'])
#  #      assert help_result.exit_code == 0
#      assert 'ewo-core 0.2.0 (Python 3.5)' in help_result.output
