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
